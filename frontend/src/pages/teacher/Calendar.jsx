import { useEffect, useState } from "react";
import api from "../../api/axios";
import Sidebar from "../../components/Sidebar";

function Calendar() {
  const [events, setEvents] = useState([]);

  useEffect(() => {
    fetchCalendar();
  }, []);

  const fetchCalendar = async () => {
    try {
      const res = await api.get("/calendar");
      setEvents(res.data);
    } catch (error) {
      console.error(error);
    }
  };

  return (
    <div>
      <Sidebar />

      <h1>Academic Calendar</h1>

      <table border="1">
        <thead>
          <tr>
            <th>ID</th>
            <th>Date</th>
            <th>Type</th>
            <th>Reason</th>
          </tr>
        </thead>

        <tbody>
          {events.map((event) => (
            <tr key={event.calendar_id}>
              <td>{event.calendar_id}</td>
              <td>{event.event_date}</td>
              <td>{event.event_type}</td>
              <td>{event.reason}</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}

export default Calendar;