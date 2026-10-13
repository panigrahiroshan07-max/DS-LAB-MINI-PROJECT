import { useEffect, useState } from "react";
import api from "../../api/axios";
import Sidebar from "../../components/Sidebar";

function CorrectionRequests() {
  const [requests, setRequests] = useState([]);

  useEffect(() => {
    fetchRequests();
  }, []);

  const fetchRequests = async () => {
    try {
      const res = await api.get("/correction-requests");
      setRequests(res.data);
    } catch (error) {
      console.error(error);
    }
  };

  const updateStatus = async (id, status) => {
    try {
      await api.put(`/correction-requests/${id}`, {
        status,
      });

      alert("Request Updated");

      fetchRequests();
    } catch (error) {
      console.error(error);
    }
  };

  return (
    <div>
      <Sidebar />

      <h1>Correction Requests</h1>

      <table border="1">
        <thead>
          <tr>
            <th>Request ID</th>
            <th>Student ID</th>
            <th>Attendance ID</th>
            <th>Reason</th>
            <th>Status</th>
            <th>Actions</th>
          </tr>
        </thead>

        <tbody>
          {requests.map((request) => (
            <tr key={request.request_id}>
              <td>{request.request_id}</td>
              <td>{request.student_id}</td>
              <td>{request.attendance_id}</td>
              <td>{request.reason}</td>
              <td>{request.status}</td>

              <td>
                <button
                  onClick={() =>
                    updateStatus(
                      request.request_id,
                      "Approved"
                    )
                  }
                >
                  Approve
                </button>

                <button
                  onClick={() =>
                    updateStatus(
                      request.request_id,
                      "Rejected"
                    )
                  }
                >
                  Reject
                </button>
              </td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}

export default CorrectionRequests;