const express = require("express");
const SerialPort = require("serialport").SerialPort;
const Readline = require("@serialport/parser-readline").ReadlineParser;

const app = express();
const portName = "COM3"; // Change this to the appropriate port name on your system
const baudRate = 9600; // Match the baud rate with the one in Arduino code
const port = new SerialPort({path: portName,  baudRate });
const parser = port.pipe(new Readline({ delimiter: "\n" }));

const dirPin = 2;
const angPin = 13;
const keyPin = 8;


app.get("/angularcommand/:dirang", (req, res) => {
  const { dirang } = req.params;
  const [direction, angle] = dirang.split("-");
  if (direction === "0" || direction === "1") {
    controlStepperAngle(direction, angle);
    res.header("Access-Control-Allow-Origin", "http://localhost:3001");
    res.header(
      "Access-Control-Allow-Headers",
      "Origin, X-Requested-With, Content-Type, Accept"
    );
    res.status(200).send("Stepper motor moving " + direction);
  } else {
    res.status(400).send("Invalid direction");
  }
});

function controlStepperAngle(direction, angle) {
  const steps = angle * 2.22222222222; 
  // One degree is approximately 2.22 steps
  port.write(`${angPin},${direction}-${steps}\n`);
}

app.get("/move/:direction", (req, res) => {
  const { direction } = req.params;
  if (direction === "clockwise" || direction === "counterclockwise") {
    controlStepper(direction, dirPin);
    res.header("Access-Control-Allow-Origin", "http://localhost:3001");
    res.header(
      "Access-Control-Allow-Headers",
      "Origin, X-Requested-With, Content-Type, Accept"
    );
    res.status(200).send("Stepper motor moving " + direction);
  } else {
    res.status(400).send("Invalid direction");
  }
});

app.get("/movekey/:direction", (req, res) => {
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
});

function controlStepper(direction, pin) {
  // Set the spinning direction
  port.write(`${pin},${direction === "clockwise" ? "1" : "0"}\n`);
}

parser.on("data", (data) => {
  console.log("Data from Arduino:", data);
});

port.on("open", () => {
  console.log("Serial port is open");
  app.listen(3000, () => {
    console.log("Web server listening on port 3000");
  });
});
