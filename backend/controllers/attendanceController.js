const db = require("../config/db");

// Mark Attendance
const markAttendance = (req, res) => {
  const {
    student_id,
    subject_id,
    attendance_date,
    lecture_number,
    status
  } = req.body;

  const sql = `
    INSERT INTO attendance
    (student_id, subject_id, attendance_date, lecture_number, status)
    VALUES (?, ?, ?, ?, ?)
  `;

  db.query(
    sql,
    [
      student_id,
      subject_id,
      attendance_date,
      lecture_number,
      status
    ],
    (err, result) => {
      if (err) {
        return res.status(500).json(err);
      }

      res.json({
        message: "Attendance Marked Successfully",
        attendanceId: result.insertId
      });
    }
  );
};

// Get Attendance of One Student
const getAttendanceByStudent = (req, res) => {
  const studentId = req.params.id;

  const sql =
    "SELECT * FROM attendance WHERE student_id = ?";

  db.query(sql, [studentId], (err, result) => {
    if (err) {
      return res.status(500).json(err);
    }

    res.json(result);
  });
};

const getAttendanceReport = (req, res) => {
  const studentId = req.params.id;

  const sql = `
    SELECT
      COUNT(*) AS total_lectures,
      SUM(CASE WHEN status='Present' THEN 1 ELSE 0 END) AS present
    FROM attendance
    WHERE student_id = ?
  `;

  db.query(sql, [studentId], (err, result) => {
    if (err) {
      return res.status(500).json(err);
    }

    const total = result[0].total_lectures;
    const present = result[0].present || 0;

    const percentage =
      total > 0 ? ((present / total) * 100).toFixed(2) : 0;

    res.json({
      student_id: studentId,
      total_lectures: total,
      present: present,
      percentage: percentage
    });
  });
};
const getDefaulters = (req, res) => {
  const sql = `
    SELECT
      s.student_id,
      s.name,
      ROUND(
        (
          SUM(CASE WHEN a.status = 'Present' THEN 1 ELSE 0 END)
          / COUNT(*)
        ) * 100,
        2
      ) AS percentage
    FROM students s
    JOIN attendance a
      ON s.student_id = a.student_id
    GROUP BY s.student_id, s.name
    HAVING percentage < 75
  `;

  db.query(sql, (err, result) => {
    if (err) {
      return res.status(500).json(err);
    }

    res.json(result);
  });
};
module.exports = {
  markAttendance,
  getAttendanceByStudent,
  getAttendanceReport,
  getDefaulters
};