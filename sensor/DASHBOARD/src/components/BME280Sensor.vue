<template>
  <div id="outherDiv">
    <div id="TemperatureDiv">
      <h1>Temperature</h1>
    </div>
    <div id="PressureDiv">
      <h1>Pressure</h1>
    </div>
    <div id="HumidityDiv">
      <h1>Humidity</h1>
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

let baseUrl = "http://10.68.254.211"

setInterval(async () => {
  let data = await fetch(baseUrl + "/BME280",{
   
    mode: 'no-cors' // no-cors, *cors, same-origin
  
  }).then(response => {
    return response.json();
  });
  console.log(data);
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
</style>
