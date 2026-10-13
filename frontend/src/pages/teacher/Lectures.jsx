import { useEffect, useState } from "react";
import api from "../../api/axios";
import Sidebar from "../../components/Sidebar";

function Lectures() {
  const [lectures, setLectures] = useState([]);

  useEffect(() => {
    fetchLectures();
  }, []);

  const fetchLectures = async () => {
    try {
      const res = await api.get("/lectures");
      setLectures(res.data);
    } catch (error) {
      console.error(error);
    }
  };

  return (
    <div>
      <Sidebar />

      <h1>Lectures</h1>

      <table border="1">
        <thead>
          <tr>
            <th>ID</th>
            <th>Subject</th>
            <th>Teacher</th>
            <th>Class</th>
            <th>Date</th>
            <th>Lecture No</th>
          </tr>
        </thead>

        <tbody>
          {lectures.map((lecture) => (
            <tr key={lecture.lecture_id}>
              <td>{lecture.lecture_id}</td>
              <td>{lecture.subject_id}</td>
              <td>{lecture.teacher_id}</td>
              <td>{lecture.class_id}</td>
              <td>{lecture.lecture_date}</td>
              <td>{lecture.lecture_number}</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}

export default Lectures;