import { useEffect, useState } from "react";
import api from "../../api/axios";
import Sidebar from "../../components/Sidebar";

function Reports() {
  const [defaulters, setDefaulters] = useState([]);

  useEffect(() => {
    fetchDefaulters();
  }, []);

  const fetchDefaulters = async () => {
    try {
      const res = await api.get("/attendance/defaulters");
      setDefaulters(res.data);
    } catch (error) {
      console.error(error);
    }
  };

  return (
    <div>
      <Sidebar />

      <h1>Attendance Reports</h1>

      <h2>Defaulters (Attendance Below 75%)</h2>

      <table border="1">
        <thead>
          <tr>
            <th>Student ID</th>
            <th>Name</th>
            <th>Attendance %</th>
          </tr>
        </thead>

        <tbody>
          {defaulters.map((student) => (
            <tr key={student.student_id}>
              <td>{student.student_id}</td>
              <td>{student.name}</td>
              <td>{student.percentage}%</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}

export default Reports;