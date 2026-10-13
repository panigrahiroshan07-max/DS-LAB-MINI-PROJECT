const db = require("../config/db");

// Add Holiday / Half-Day
const createEvent = (req, res) => {
  const { event_date, event_type, reason } = req.body;

  const sql = `
    INSERT INTO academic_calendar
    (event_date, event_type, reason)
    VALUES (?, ?, ?)
  `;

  db.query(
    sql,
    [event_date, event_type, reason],
    (err, result) => {
      if (err) {
        return res.status(500).json(err);
      }

      res.json({
        message: "Event Added Successfully",
        calendarId: result.insertId,
      });
    }
  );
};

// View All Events
const getAllEvents = (req, res) => {
  const sql = "SELECT * FROM academic_calendar";

  db.query(sql, (err, result) => {
    if (err) {
      return res.status(500).json(err);
    }

    res.json(result);
  });
};

// Update Event
const updateEvent = (req, res) => {
  const id = req.params.id;

  const { event_date, event_type, reason } = req.body;

  const sql = `
    UPDATE academic_calendar
    SET event_date = ?, event_type = ?, reason = ?
    WHERE calendar_id = ?
  `;

  db.query(
    sql,
    [event_date, event_type, reason, id],
    (err, result) => {
      if (err) {
        return res.status(500).json(err);
      }

      res.json({
        message: "Event Updated Successfully",
      });
    }
  );
};

// Delete Event
const deleteEvent = (req, res) => {
  const id = req.params.id;

  const sql =
    "DELETE FROM academic_calendar WHERE calendar_id = ?";

  db.query(sql, [id], (err, result) => {
    if (err) {
      return res.status(500).json(err);
    }

    res.json({
      message: "Event Deleted Successfully",
    });
  });
};

module.exports = {
  createEvent,
  getAllEvents,
  updateEvent,
  deleteEvent,
};