const db = require("../config/db");

const getAllTeachers = (req, res) => {
  db.query("SELECT * FROM teachers", (err, result) => {
    if (err) return res.status(500).json(err);

    res.json(result);
  });
};

const getTeacherById = (req, res) => {
  const id = req.params.id;

  db.query(
    "SELECT * FROM teachers WHERE teacher_id = ?",
    [id],
    (err, result) => {
      if (err) return res.status(500).json(err);

      res.json(result);
    }
  );
};

const createTeacher = (req, res) => {
  const { name, email } = req.body;

  db.query(
    "INSERT INTO teachers(name,email) VALUES (?,?)",
    [name, email],
    (err, result) => {
      if (err) return res.status(500).json(err);

      res.json({
        message: "Teacher Added Successfully",
        teacherId: result.insertId,
      });
    }
  );
};

const updateTeacher = (req, res) => {
  const id = req.params.id;
  const { name, email } = req.body;

  db.query(
    "UPDATE teachers SET name=?, email=? WHERE teacher_id=?",
    [name, email, id],
    (err, result) => {
      if (err) return res.status(500).json(err);

      res.json({
        message: "Teacher Updated Successfully",
      });
    }
  );
};

const deleteTeacher = (req, res) => {
  const id = req.params.id;

  db.query(
    "DELETE FROM teachers WHERE teacher_id=?",
    [id],
    (err, result) => {
      if (err) return res.status(500).json(err);

      res.json({
        message: "Teacher Deleted Successfully",
      });
    }
  );
};

module.exports = {
  getAllTeachers,
  getTeacherById,
  createTeacher,
  updateTeacher,
  deleteTeacher,
};