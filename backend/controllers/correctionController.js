const db = require("../config/db");

// Create Correction Request
const createRequest = (req, res) => {
  const { student_id, attendance_id, reason } = req.body;

  const sql = `
    INSERT INTO correction_requests
    (student_id, attendance_id, reason, status)
    VALUES (?, ?, ?, 'Pending')
  `;

  db.query(
    sql,
    [student_id, attendance_id, reason],
    (err, result) => {
      if (err) {
        return res.status(500).json(err);
      }

      res.json({
        message: "Request Submitted Successfully",
        requestId: result.insertId,
      });
    }
  );
};

// View All Requests
const getAllRequests = (req, res) => {
  const sql = "SELECT * FROM correction_requests";

  db.query(sql, (err, result) => {
    if (err) {
      return res.status(500).json(err);
    }

    res.json(result);
  });
};

// Approve / Reject Request
const updateRequestStatus = (req, res) => {
  const requestId = req.params.id;
  const { status } = req.body;

  const sql =
    "UPDATE correction_requests SET status = ? WHERE request_id = ?";

  db.query(sql, [status, requestId], (err, result) => {
    if (err) {
      return res.status(500).json(err);
    }

    res.json({
      message: "Request Status Updated Successfully",
    });
  });
};
const getRequestsByStudent = (req, res) => {
  const studentId = req.params.id;

  const sql =
    "SELECT * FROM correction_requests WHERE student_id = ?";

  db.query(sql, [studentId], (err, result) => {
    if (err) {
      return res.status(500).json(err);
    }

    res.json(result);
  });
};
module.exports = {
  createRequest,
  getAllRequests,
  updateRequestStatus,
  getRequestsByStudent,
};