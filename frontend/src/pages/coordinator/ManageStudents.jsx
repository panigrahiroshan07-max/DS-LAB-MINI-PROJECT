import { useEffect, useState } from "react";
import api from "../../api/axios";

function ManageStudents() {
  const [students, setStudents] = useState([]);
  const [searchId, setSearchId] = useState("");

  const [newStudent, setNewStudent] = useState({
    roll_no: "",
    name: "",
    class_id: ""
  });

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

  const addStudent = async () => {
    try {
      await api.post("/students", newStudent);

      setNewStudent({
        roll_no: "",
        name: "",
        class_id: ""
      });

      fetchStudents();
    } catch (error) {
      console.error(error);
      alert("Failed to add student");
    }
  };

  const deleteStudent = async (id) => {
    try {
      await api.delete(`/students/${id}`);
      fetchStudents();
    } catch (error) {
      console.error(error);
    }
  };

  const filteredStudents = students.filter((student) =>
    student.student_id
      .toString()
      .includes(searchId)
  );

  return (
    <div className="container">

      <h1>Manage Students</h1>

      {/* Count Operation */}

      <div className="card">
        <h3>Total Students: {students.length}</h3>
      </div>

      {/* Insert Operation */}

      <div className="card">
        <h3>Add Student</h3>

        <input
          type="text"
          placeholder="Roll Number"
          value={newStudent.roll_no}
          onChange={(e) =>
            setNewStudent({
              ...newStudent,
              roll_no: e.target.value
            })
          }
        />

        <br /><br />

        <input
          type="text"
          placeholder="Student Name"
          value={newStudent.name}
          onChange={(e) =>
            setNewStudent({
              ...newStudent,
              name: e.target.value
            })
          }
        />

        <br /><br />

        <input
          type="number"
          placeholder="Class ID"
          value={newStudent.class_id}
          onChange={(e) =>
            setNewStudent({
              ...newStudent,
              class_id: e.target.value
            })
          }
        />

        <br /><br />

        <button onClick={addStudent}>
          Add Student
        </button>
      </div>

      {/* Search Operation */}

      <div className="card">
        <h3>Search Student</h3>

        <input
          type="text"
          placeholder="Search by Student ID"
          value={searchId}
          onChange={(e) => setSearchId(e.target.value)}
        />
      </div>

      {/* Traversal Operation */}

      <div className="card">
        <h3>Student Records</h3>

        <table border="1" width="100%">
          <thead>
            <tr>
              <th>ID</th>
              <th>Roll No</th>
              <th>Name</th>
              <th>Class</th>
              <th>Action</th>
            </tr>
          </thead>

          <tbody>
            {filteredStudents.map((student) => (
              <tr key={student.student_id}>
                <td>{student.student_id}</td>
                <td>{student.roll_no}</td>
                <td>{student.name}</td>
                <td>{student.class_id}</td>

                <td>
                  <button
                    onClick={() =>
                      deleteStudent(student.student_id)
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

      {/* DS Explanation */}

      <div className="card">
        <h3>Linked List Operations Used</h3>

        <ul>
          <li>Add Student → Insert Node</li>
          <li>Display Students → Traversal</li>
          <li>Search Student → Search</li>
          <li>Delete Student → Delete Node</li>
          <li>Total Students → Count Nodes</li>
        </ul>
      </div>

    </div>
  );
}

export default ManageStudents;