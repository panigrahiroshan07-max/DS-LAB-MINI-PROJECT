import { useEffect, useState } from "react";
import api from "../api/axios";

function LinkedListDemo() {
  const [output, setOutput] = useState("");

  useEffect(() => {
    fetchLinkedList();
  }, []);

  const fetchLinkedList = async () => {
    try {
    const res = await api.get("/api/ds/students-linkedlist");
      setOutput(res.data.output);
    } catch (error) {
      console.error(error);
    }
  };

  return (
    <div style={{ padding: "20px" }}>
      <h1>Student Linked List (C)</h1>

      <pre>{output}</pre>
    </div>
  );
}

export default LinkedListDemo;