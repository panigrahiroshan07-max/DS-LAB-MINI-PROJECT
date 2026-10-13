require("dotenv").config();

const express = require("express");
const cors = require("cors");

const app = express();

app.use(cors());
app.use(express.json());

const studentRoutes = require("./routes/students");
const teacherRoutes = require("./routes/teachers");
const lectureRoutes = require("./routes/lectures");
const attendanceRoutes = require("./routes/attendance");
const correctionRoutes = require("./routes/correctionRequests");
const calendarRoutes = require("./routes/calendar");
const timetableRoutes = require("./routes/timetable");
const authRoutes = require("./routes/auth");

app.use("/students", studentRoutes);
app.use("/teachers", teacherRoutes);
app.use("/lectures", lectureRoutes);
app.use("/attendance", attendanceRoutes);
app.use("/correction-requests", correctionRoutes);
app.use("/calendar", calendarRoutes);
app.use("/timetable", timetableRoutes);
app.use("/auth", authRoutes);

app.get("/", (req, res) => {
  res.send("Smart Attendance Backend Running");
});

const PORT = process.env.PORT || 5000;

app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});

const dsRoutes = require("./routes/dsRoutes");

app.use("/api/ds", dsRoutes);