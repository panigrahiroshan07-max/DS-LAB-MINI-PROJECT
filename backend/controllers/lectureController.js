const db = require("../config/db");

const createLecture = (req, res) => {
  const {
    subject_id,
    teacher_id,
    class_id,
    lecture_date,
    lecture_number,
    lecture_type,
    remarks
  } = req.body;

  const sql = `
    INSERT INTO lectures
    (subject_id, teacher_id, class_id,
     lecture_date, lecture_number,
     lecture_type, remarks)
    VALUES (?, ?, ?, ?, ?, ?, ?)
  `;

  db.query(
    sql,
    [
      subject_id,
      teacher_id,
      class_id,
      lecture_date,
      lecture_number,
      lecture_type,
      remarks
    ],
    (err, result) => {
      if (err) return res.status(500).json(err);

      res.json({
        message: "Lecture Created Successfully",
        lectureId: result.insertId
      });
    }
  );
};

const getAllLectures = (req, res) => {
  db.query("SELECT * FROM lectures", (err, result) => {
    if (err) return res.status(500).json(err);

    res.json(result);
  });
};

const getLecturesByClass = (req, res) => {
  const classId = req.params.id;

  const sql = "SELECT * FROM lectures WHERE class_id = ?";

  db.query(sql, [classId], (err, result) => {
    if (err) {
      return res.status(500).json(err);
    }

    res.json(result);
  });
};

const getLecturesByTeacher = (req, res) => {
  const teacherId = req.params.id;

  const sql = "SELECT * FROM lectures WHERE teacher_id = ?";

  db.query(sql, [teacherId], (err, result) => {
    if (err) {
      return res.status(500).json(err);
    }

    res.json(result);
  });
};

const getLecturesBySubject = (req, res) => {
  const subjectId = req.params.id;

  const sql = "SELECT * FROM lectures WHERE subject_id = ?";

  db.query(sql, [subjectId], (err, result) => {
    if (err) {
      return res.status(500).json(err);
    }

    res.json(result);
  });
};

const getLectureStatsBySubject = (req, res) => {
  const subjectId = req.params.id;

  const sql = `
    SELECT
      COUNT(*) AS total_lectures,

      SUM(CASE WHEN lecture_type='Regular'
        THEN 1 ELSE 0 END) AS regular_lectures,

      SUM(CASE WHEN lecture_type='Extra'
        THEN 1 ELSE 0 END) AS extra_lectures,

      SUM(CASE WHEN lecture_type='Cancelled'
        THEN 1 ELSE 0 END) AS cancelled_lectures,

      SUM(CASE WHEN lecture_type='Holiday'
        THEN 1 ELSE 0 END) AS holiday_lectures,

      SUM(CASE WHEN lecture_type='HalfDay'
        THEN 1 ELSE 0 END) AS halfday_lectures

    FROM lectures
    WHERE subject_id = ?
  `;

  db.query(sql, [subjectId], (err, result) => {
    if (err) {
      return res.status(500).json(err);
    }

    res.json(result[0]);
  });
};

const cancelLecture = (req, res) => {
  const lectureId = req.params.id;
  const { remarks } = req.body;

  const sql = `
    UPDATE lectures
    SET lecture_type = 'Cancelled',
        remarks = ?
    WHERE lecture_id = ?
  `;

  db.query(sql, [remarks, lectureId], (err, result) => {
    if (err) {
      return res.status(500).json(err);
    }

    res.json({
      message: "Lecture Cancelled Successfully"
    });
  });
};

module.exports = {
  createLecture,
  getAllLectures,
  getLecturesByClass,
  getLecturesByTeacher,
  getLecturesBySubject,
  getLectureStatsBySubject,
  cancelLecture
};