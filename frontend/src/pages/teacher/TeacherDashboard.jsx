import { useEffect, useState } from "react";
import api from "../../api/axios";
import Sidebar from "../../components/Sidebar";

function TeacherDashboard() {
  const [students, setStudents] = useState(0);
  const [lectures, setLectures] = useState(0);
  const [requests, setRequests] = useState(0);

  useEffect(() => {
    fetchDashboardData();
  }, []);

  const fetchDashboardData = async () => {
    try {
      const studentsRes = await api.get("/students");
      setStudents(studentsRes.data.length);

      const lecturesRes = await api.get("/lectures");
      setLectures(lecturesRes.data.length);

      const requestsRes = await api.get("/correction-requests");

      const pending = requestsRes.data.filter(
        (r) => r.status === "Pending"
      );

      setRequests(pending.length);
    } catch (error) {
      console.error(error);
    }
  };

  return (
    <div>
      <Sidebar />
      <h1>Teacher Dashboard</h1>

      <h3>Total Students: {students}</h3>

      <h3>Total Lectures: {lectures}</h3>

      <h3>Pending Requests: {requests}</h3>
    </div>
  );
}

export default TeacherDashboard;