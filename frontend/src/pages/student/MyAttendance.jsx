import { useEffect, useState } from "react";
import api from "../../api/axios";
import Sidebar from "../../components/Sidebar";

function MyAttendance() {
  const [records, setRecords] = useState([]);
  const [report, setReport] = useState(null);

  const userId = localStorage.getItem("user_id");

  useEffect(() => {
    fetchAttendance();
    fetchReport();
  }, []);

  const fetchAttendance = async () => {
    try {
      const res = await api.get(
        `/attendance/student/${userId}`
      );

      setRecords(res.data);
    } catch (error) {
      console.error(error);
    }
  };

  const fetchReport = async () => {
    try {
      const res = await api.get(
        `/attendance/report/student/${userId}`
      );

      setReport(res.data);
    } catch (error) {
      console.error(error);
    }
  };

  return (
    <div>
      <Sidebar />

      <h1>My Attendance</h1>

      {report && (
        <div>
          <h3>Total Lectures: {report.total_lectures}</h3>
          <h3>Present: {report.present}</h3>
          <h3>Percentage: {report.percentage}%</h3>
        </div>
      )}

      <table border="1">
        <thead>
          <tr>
            <th>ID</th>
            <th>Subject</th>
            <th>Date</th>
            <th>Lecture</th>
            <th>Status</th>
          </tr>
        </thead>

        <tbody>
          {records.map((item) => (
            <tr key={item.attendance_id}>
              <td>{item.attendance_id}</td>
              <td>{item.subject_id}</td>
              <td>{item.attendance_date}</td>
              <td>{item.lecture_number}</td>
              <td>{item.status}</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}

export default MyAttendance;