const db = require("../config/db");

const getAllStudents = (req, res) => {
  const sql = "SELECT * FROM students";

  db.query(sql, (err, result) => {
    if (err) {
      return res.status(500).json(err);
    }

    res.json(result);
  });
};

const getStudentById = (req, res) => {
  const id = req.params.id;

  const sql = "SELECT * FROM students WHERE student_id = ?";

  db.query(sql, [id], (err, result) => {
    if (err) {
      return res.status(500).json(err);
    }

    res.json(result);
  });
};

const createStudent = (req, res) => {
  const { roll_no, name, email, class_id } = req.body;

  const sql =
    "INSERT INTO students (roll_no, name, email, class_id) VALUES (?, ?, ?, ?)";

  db.query(sql, [roll_no, name, email, class_id], (err, result) => {
    if (err) {
      return res.status(500).json(err);
    }

    res.json({
      message: "Student Added Successfully",
      studentId: result.insertId,
    });
  });
};

const updateStudent = (req, res) => {
  const id = req.params.id;
  const { roll_no, name, email, class_id } = req.body;

  const sql =
    "UPDATE students SET roll_no=?, name=?, email=?, class_id=? WHERE student_id=?";

  db.query(
    sql,
    [roll_no, name, email, class_id, id],
    (err, result) => {
      if (err) {
        return res.status(500).json(err);
      }

      res.json({
        message: "Student Updated Successfully",
      });
    }
  );
};

const deleteStudent = (req, res) => {
  const id = req.params.id;

  const sql = "DELETE FROM students WHERE student_id=?";

  db.query(sql, [id], (err, result) => {
    if (err) {
      return res.status(500).json(err);
    }

    res.json({
      message: "Student Deleted Successfully",
    });
  });
};

module.exports = {
  getAllStudents,
  getStudentById,
  createStudent,
  updateStudent,
  deleteStudent,
};