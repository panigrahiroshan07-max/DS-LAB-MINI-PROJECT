import { useEffect, useState } from "react";
import api from "../../api/axios";
import Sidebar from "../../components/Sidebar";

function CoordinatorDashboard() {
  const [students, setStudents] = useState(0);
  const [lectures, setLectures] = useState(0);
  const [events, setEvents] = useState(0);
  const [defaulters, setDefaulters] = useState(0);

  useEffect(() => {
    fetchDashboardData();
  }, []);

  const fetchDashboardData = async () => {
    try {
      const studentsRes = await api.get("/students");
      const lecturesRes = await api.get("/lectures");
      const eventsRes = await api.get("/calendar");
      const defaultersRes = await api.get("/attendance/defaulters");

      setStudents(studentsRes.data.length);
      setLectures(lecturesRes.data.length);
      setEvents(eventsRes.data.length);
      setDefaulters(defaultersRes.data.length);
    } catch (error) {
      console.error(error);
    }
  };

  return (
    <div>
      <Sidebar />
      <h1>Coordinator Dashboard</h1>

      <h3>Total Students: {students}</h3>

      <h3>Total Lectures: {lectures}</h3>

      <h3>Total Calendar Events: {events}</h3>

      <h3>Defaulters: {defaulters}</h3>
    </div>
  );
}

export default CoordinatorDashboard;