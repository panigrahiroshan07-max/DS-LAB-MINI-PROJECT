import { useState } from "react";
import api from "../../api/axios";
import Sidebar from "../../components/Sidebar";

function Attendance() {
  const [studentId, setStudentId] = useState("");
  const [subjectId, setSubjectId] = useState("");
  const [lectureNumber, setLectureNumber] = useState("");
  const [status, setStatus] = useState("Present");

  const markAttendance = async () => {
    try {
      await api.post("/attendance/mark", {
        student_id: studentId,
        subject_id: subjectId,
        lecture_number: lectureNumber,
        status: status,
      });

      alert("Attendance Marked Successfully");
    } catch (error) {
      console.error(error);
      alert("Error marking attendance");
    }
  };

  return (
    <div>
      <Sidebar />

      <h1>Attendance</h1>

      <input
        type="number"
        placeholder="Student ID"
        value={studentId}
        onChange={(e) => setStudentId(e.target.value)}
      />

      <br /><br />

      <input
        type="number"
        placeholder="Subject ID"
        value={subjectId}
        onChange={(e) => setSubjectId(e.target.value)}
      />

      <br /><br />

      <input
        type="number"
        placeholder="Lecture Number"
        value={lectureNumber}
        onChange={(e) => setLectureNumber(e.target.value)}
      />

      <br /><br />

      <select
        value={status}
        onChange={(e) => setStatus(e.target.value)}
      >
        <option value="Present">Present</option>
        <option value="Absent">Absent</option>
      </select>

      <br /><br />

      <button onClick={markAttendance}>
        Mark Attendance
      </button>
    </div>
  );
}

export default Attendance;