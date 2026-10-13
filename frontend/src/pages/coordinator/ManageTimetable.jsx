import { useEffect, useState } from "react";
import api from "../../api/axios";
import Sidebar from "../../components/Sidebar";

function ManageTimetable() {
  const [timetable, setTimetable] = useState([]);

  const [classId, setClassId] = useState("");
  const [dayName, setDayName] = useState("");
  const [lectureSlot, setLectureSlot] = useState("");
  const [subjectId, setSubjectId] = useState("");

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

  const addTimetable = async () => {
    try {
      await api.post("/timetable", {
        class_id: classId,
        day_name: dayName,
        lecture_slot: lectureSlot,
        subject_id: subjectId,
      });

      alert("Timetable Entry Added");

      setClassId("");
      setDayName("");
      setLectureSlot("");
      setSubjectId("");

      fetchTimetable();
    } catch (error) {
      console.error(error);
    }
  };

  const deleteTimetable = async (id) => {
    try {
      await api.delete(`/timetable/${id}`);

      alert("Timetable Deleted");

      fetchTimetable();
    } catch (error) {
      console.error(error);
    }
  };

  return (
    <div>
      <Sidebar />

      <h1>Manage Timetable</h1>

      <h3>Add Timetable Entry</h3>

      <input
        type="number"
        placeholder="Class ID"
        value={classId}
        onChange={(e) => setClassId(e.target.value)}
      />

      <br /><br />

      <input
        placeholder="Day Name"
        value={dayName}
        onChange={(e) => setDayName(e.target.value)}
      />

      <br /><br />

      <input
        placeholder="Lecture Slot"
        value={lectureSlot}
        onChange={(e) => setLectureSlot(e.target.value)}
      />

      <br /><br />

      <input
        type="number"
        placeholder="Subject ID"
        value={subjectId}
        onChange={(e) => setSubjectId(e.target.value)}
      />

      <br /><br />

      <button onClick={addTimetable}>
        Add Timetable
      </button>

      <hr />

      <table border="1">
        <thead>
          <tr>
            <th>ID</th>
            <th>Class ID</th>
            <th>Day</th>
            <th>Lecture Slot</th>
            <th>Subject ID</th>
            <th>Action</th>
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

              <td>
                <button
                  onClick={() =>
                    deleteTimetable(item.timetable_id)
                  }
                >
                  Delete
                </button>
              </td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}

export default ManageTimetable;