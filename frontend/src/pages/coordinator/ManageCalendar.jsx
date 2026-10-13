import { useEffect, useState } from "react";
import api from "../../api/axios";
import Sidebar from "../../components/Sidebar";

function ManageCalendar() {
  const [events, setEvents] = useState([]);

  const [eventDate, setEventDate] = useState("");
  const [eventType, setEventType] = useState("");
  const [reason, setReason] = useState("");

  useEffect(() => {
    fetchEvents();
  }, []);

  const fetchEvents = async () => {
    try {
      const res = await api.get("/calendar");
      setEvents(res.data);
    } catch (error) {
      console.error(error);
    }
  };

  const addEvent = async () => {
    try {
      await api.post("/calendar", {
        event_date: eventDate,
        event_type: eventType,
        reason: reason,
      });

      alert("Event Added Successfully");

      setEventDate("");
      setEventType("");
      setReason("");

      fetchEvents();
    } catch (error) {
      console.error(error);
    }
  };

  const deleteEvent = async (id) => {
    try {
      await api.delete(`/calendar/${id}`);

      alert("Event Deleted Successfully");

      fetchEvents();
    } catch (error) {
      console.error(error);
    }
  };

  return (
    <div>
      <Sidebar />

      <h1>Manage Calendar</h1>

      <h3>Add Event</h3>

      <input
        type="date"
        value={eventDate}
        onChange={(e) => setEventDate(e.target.value)}
      />

      <br /><br />

      <select
        value={eventType}
        onChange={(e) => setEventType(e.target.value)}
      >
        <option value="">Select Type</option>
        <option value="Holiday">Holiday</option>
        <option value="HalfDay">HalfDay</option>
        <option value="Exam">Exam</option>
        <option value="Event">Event</option>
      </select>

      <br /><br />

      <input
        placeholder="Reason"
        value={reason}
        onChange={(e) => setReason(e.target.value)}
      />

      <br /><br />

      <button onClick={addEvent}>
        Add Event
      </button>

      <hr />

      <table border="1">
        <thead>
          <tr>
            <th>ID</th>
            <th>Date</th>
            <th>Type</th>
            <th>Reason</th>
            <th>Action</th>
          </tr>
        </thead>

        <tbody>
          {events.map((event) => (
            <tr key={event.calendar_id}>
              <td>{event.calendar_id}</td>
              <td>{event.event_date}</td>
              <td>{event.event_type}</td>
              <td>{event.reason}</td>
              <td>
                <button
                  onClick={() =>
                    deleteEvent(event.calendar_id)
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

export default ManageCalendar;