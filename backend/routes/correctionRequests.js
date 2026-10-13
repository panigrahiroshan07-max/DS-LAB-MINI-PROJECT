const express = require("express");

const router = express.Router();

const verifyToken = require("../middleware/authMiddleware");
const authorizeRoles = require("../middleware/roleMiddleware");

const {
  createRequest,
  getAllRequests,
  updateRequestStatus,
  getRequestsByStudent,
} = require("../controllers/correctionController");

// Student creates request
router.post(
  "/",
  verifyToken,
  authorizeRoles("student"),
  createRequest
);

// Student views own requests
router.get(
  "/student/:id",
  verifyToken,
  authorizeRoles("student"),
  getRequestsByStudent
);

// Teacher/Coordinator view all requests
router.get(
  "/",
  verifyToken,
  authorizeRoles("teacher", "coordinator"),
  getAllRequests
);

// Teacher updates request status
router.put(
  "/:id",
  verifyToken,
  authorizeRoles("teacher"),
  updateRequestStatus
);

module.exports = router;