import { useEffect, useState } from "react";
import api from "../../api/axios";
import Sidebar from "../../components/Sidebar";

function Timetable() {
  const [timetable, setTimetable] = useState([]);

  useEffect(() => {
    fetchTimetable();
  }, []);

  const fetchTimetable = async () => {
    try {
      const res = await api.get("/timetable");
      setTimetable(res.data);
    } catch (error) {
      console.error(error);
    }
  };

  return (
    <div>
      <Sidebar />

      <h1>Timetable</h1>

      <table border="1">
        <thead>
          <tr>
            <th>ID</th>
            <th>Class ID</th>
            <th>Day</th>
            <th>Lecture Slot</th>
            <th>Subject ID</th>
          </tr>
        </thead>

        <tbody>
          {timetable.map((item) => (
            <tr key={item.timetable_id}>
              <td>{item.timetable_id}</td>
              <td>{item.class_id}</td>
              <td>{item.day_name}</td>
              <td>{item.lecture_slot}</td>
              <td>{item.subject_id}</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}

export default Timetable;