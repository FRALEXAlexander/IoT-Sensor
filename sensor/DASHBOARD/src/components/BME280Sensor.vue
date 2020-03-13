<template>
  <div id="outherDiv">
    <div id="TemperatureDiv">
      <h1>Temperature</h1>
      <p id="Temperature"></p>
    </div>
    <div id="PressureDiv">
      <h1>Pressure</h1>
       <p id="Pressure"></p>
    </div>
    <div id="HumidityDiv">
      <h1>Humidity</h1>
       <p id="Humidity"></p>
    </div>
    <div id="AltitudeDiv">
      <h1>Altitude</h1>
       <p id="Altitude"></p>
    </div>
  </div>
</template>

<script>
export default {
  name: "BME280Sensor",
  props: {
    msg: String
  }
};

setInterval(async () => {
  let data = await fetch("http://localhost:2000 /BME280", {
  
}).then(function(response) {
  // Do something with response
   //console.log(response.text());
    return response.json();
});
//console.log(data)
document.getElementById("Temperature").innerHTML = data.temperature;
document.getElementById("Pressure").innerHTML = data.pressure;
document.getElementById("Humidity").innerHTML = data.humidity;
document.getElementById("Altitude").innerHTML = data.altitude;
}, 5000);

</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
#outherDiv {
  background-color: aqua;
}
#TemperatureDiv {
  background-color: blue;
}
#PressureDiv {
  background-color: red;
}
#HumidityDiv {
  background-color: green;
}
#AltitudeDiv {
  background-color: blueviolet;
}
</style>
