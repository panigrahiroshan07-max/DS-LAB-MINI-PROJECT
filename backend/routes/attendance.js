const express = require("express");
const router = express.Router();

const {
  markAttendance,
  getAttendanceByStudent,
  getAttendanceReport,
  getDefaulters
} = require("../controllers/attendanceController");
router.post("/mark", markAttendance);

router.get("/student/:id", getAttendanceByStudent);
router.get("/report/student/:id", getAttendanceReport);
router.get("/defaulters", getDefaulters);

module.exports = router;