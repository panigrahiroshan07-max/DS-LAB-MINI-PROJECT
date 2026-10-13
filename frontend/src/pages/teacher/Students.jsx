import { useEffect, useState } from "react";
import api from "../../api/axios";
import Sidebar from "../../components/Sidebar";

function Students() {
  const [students, setStudents] = useState([]);

  useEffect(() => {
    fetchStudents();
  }, []);

  const fetchStudents = async () => {
    try {
      const res = await api.get("/students");
      setStudents(res.data);
    } catch (error) {
      console.error(error);
    }
  };

  return (
    <div>
        <Sidebar />
      <h1>Students</h1>

      <table border="1">
        <thead>
          <tr>
            <th>ID</th>
            <th>Roll No</th>
            <th>Name</th>
            <th>Email</th>
          </tr>
        </thead>

        <tbody>
          {students.map((student) => (
            <tr key={student.student_id}>
              <td>{student.student_id}</td>
              <td>{student.roll_no}</td>
              <td>{student.name}</td>
              <td>{student.email}</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
  
}

export default Students;