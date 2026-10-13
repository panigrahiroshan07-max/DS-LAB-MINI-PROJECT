const express = require("express");

const router = express.Router();

const verifyToken = require("../middleware/authMiddleware");
const authorizeRoles = require("../middleware/roleMiddleware");

const {
  createEvent,
  getAllEvents,
  updateEvent,
  deleteEvent,
} = require("../controllers/calendarController");

// View Calendar (All Roles)
router.get("/", getAllEvents);

// Coordinator Only
router.post(
  "/",
  verifyToken,
  authorizeRoles("coordinator"),
  createEvent
);

router.put(
  "/:id",
  verifyToken,
  authorizeRoles("coordinator"),
  updateEvent
);

router.delete(
  "/:id",
  verifyToken,
  authorizeRoles("coordinator"),
  deleteEvent
);

module.exports = router;