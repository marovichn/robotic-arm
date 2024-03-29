const express = require("express");
const SerialPort = require("serialport").SerialPort;
const Readline = require("@serialport/parser-readline").ReadlineParser;

const app = express();
const portName = "COM3"; // Change this to the appropriate port name on your system
const baudRate = 9600; // Match the baud rate with the one in Arduino code
const port = new SerialPort({ path: portName, baudRate });
const parser = port.pipe(new Readline({ delimiter: "\n" }));

function controlStepper(ankle, direction, steps) {
  port.write(`${ankle}-${direction}-${steps}\n`);
}
app.get("/angularcommand/:usersettings", (req, res) => {
  const { usersettings } = req.params;
  const [ankle, direction, angle] = usersettings.split("-");
  const steps = angle * 2.22222222222; // Assuming 1 degree step for stepper motor
  if (direction === "0" || direction === "1") {
    controlStepper(ankle, direction, steps);
    res.header("Access-Control-Allow-Origin", "http://localhost:3001");
    res.header(
      "Access-Control-Allow-Headers",
      "Origin, X-Requested-With, Content-Type, Accept"
    );
    res
      .status(200)
      .send(
        "Stepper motor moving " + direction === "1"
          ? "clockwise"
          : "counterclockwise"
      );
  } else {
    res.status(400).send("Invalid direction");
  }
});

app.get("/move/:usersettings", (req, res) => {
  const { usersettings } = req.params;
  const [ankle, direction, steps] = usersettings.split("-");
  if (direction === "0" || direction === "1") {
    controlStepper(ankle, direction, steps);
    res.header("Access-Control-Allow-Origin", "http://localhost:3001");
    res.header(
      "Access-Control-Allow-Headers",
      "Origin, X-Requested-With, Content-Type, Accept"
    );
    res
      .status(200)
      .send(
        "Stepper motor moving " + direction === "1"
          ? "clockwise"
          : "counterclockwise"
      );
  } else {
    res.status(400).send("Invalid direction");
  }
});

/* app.get("/movekey/:direction", (req, res) => {
  const { direction } = req.params;
  if (direction === "clockwise" || direction === "counterclockwise") {
    controlStepper(direction, 8);
    res.header("Access-Control-Allow-Origin", "http://localhost:3001");
    res.header(
      "Access-Control-Allow-Headers",
      "Origin, X-Requested-With, Content-Type, Accept"
    );
    res.status(200).send("Stepper motor moving " + direction);
  } else {
    res.status(400).send("Invalid direction");
  }
}); */

parser.on("data", (data) => {
  console.log("Data from Arduino:", data);
});

port.on("open", () => {
  console.log("Serial port is open");
  app.listen(3000, () => {
    console.log("Web server listening on port 3000");
  });
});
