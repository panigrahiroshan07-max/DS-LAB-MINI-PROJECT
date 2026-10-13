const db = require("../config/db");

// Add Timetable Entry
const createTimetable = (req, res) => {
  const { class_id, day_name, lecture_slot, subject_id } = req.body;

  const sql = `
    INSERT INTO timetable
    (class_id, day_name, lecture_slot, subject_id)
    VALUES (?, ?, ?, ?)
  `;

  db.query(
    sql,
    [class_id, day_name, lecture_slot, subject_id],
    (err, result) => {
      if (err) return res.status(500).json(err);

      res.json({
        message: "Timetable Entry Added",
        timetableId: result.insertId,
      });
    }
  );
};

// View All Timetable
const getAllTimetable = (req, res) => {
  const sql = "SELECT * FROM timetable";

  db.query(sql, (err, result) => {
    if (err) return res.status(500).json(err);

    res.json(result);
  });
};

// Timetable By Class
const getTimetableByClass = (req, res) => {
  const classId = req.params.id;

  const sql = `
    SELECT *
    FROM timetable
    WHERE class_id = ?
  `;

  db.query(sql, [classId], (err, result) => {
    if (err) return res.status(500).json(err);

    res.json(result);
  });
};

// Update Timetable
const updateTimetable = (req, res) => {
  const id = req.params.id;

  const { class_id, day_name, lecture_slot, subject_id } = req.body;

  const sql = `
    UPDATE timetable
    SET class_id = ?,
        day_name = ?,
        lecture_slot = ?,
        subject_id = ?
    WHERE timetable_id = ?
  `;

  db.query(
    sql,
    [class_id, day_name, lecture_slot, subject_id, id],
    (err, result) => {
      if (err) return res.status(500).json(err);

      res.json({
        message: "Timetable Updated Successfully",
      });
    }
  );
};

// Delete Timetable
const deleteTimetable = (req, res) => {
  const id = req.params.id;

  const sql =
    "DELETE FROM timetable WHERE timetable_id = ?";

  db.query(sql, [id], (err, result) => {
    if (err) return res.status(500).json(err);

    res.json({
      message: "Timetable Deleted Successfully",
    });
  });
};

module.exports = {
  createTimetable,
  getAllTimetable,
  getTimetableByClass,
  updateTimetable,
  deleteTimetable,
};