import { useEffect, useState } from "react";
import api from "../../api/axios";
import Sidebar from "../../components/Sidebar";

function MyRequests() {
  const [requests, setRequests] = useState([]);

  const [attendanceId, setAttendanceId] = useState("");
  const [reason, setReason] = useState("");

  const userId = localStorage.getItem("user_id");

  useEffect(() => {
    fetchRequests();
  }, []);

  const fetchRequests = async () => {
    try {
      const res = await api.get(
        `/correction-requests/student/${userId}`
      );

      setRequests(res.data);
    } catch (error) {
      console.error(error);
    }
  };

  const submitRequest = async () => {
    try {
      await api.post("/correction-requests", {
        student_id: userId,
        attendance_id: attendanceId,
        reason: reason,
      });

      alert("Request Submitted Successfully");

      setAttendanceId("");
      setReason("");

      fetchRequests();
    } catch (error) {
      console.error(error);
      alert("Error submitting request");
    }
  };

  return (
    <div>
      <Sidebar />

      <h1>My Correction Requests</h1>

      <h3>Submit New Request</h3>

      <input
        type="number"
        placeholder="Attendance ID"
        value={attendanceId}
        onChange={(e) =>
          setAttendanceId(e.target.value)
        }
      />

      <br /><br />

      <textarea
        placeholder="Reason"
        value={reason}
        onChange={(e) =>
          setReason(e.target.value)
        }
      />

      <br /><br />

      <button onClick={submitRequest}>
        Submit Request
      </button>

      <hr />

      <h3>My Requests</h3>

      <table border="1">
        <thead>
          <tr>
            <th>Request ID</th>
            <th>Attendance ID</th>
            <th>Reason</th>
            <th>Status</th>
          </tr>
        </thead>

        <tbody>
          {requests.map((request) => (
            <tr key={request.request_id}>
              <td>{request.request_id}</td>
              <td>{request.attendance_id}</td>
              <td>{request.reason}</td>
              <td>{request.status}</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}

export default MyRequests;