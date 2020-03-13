<template>
  <div id="outherDiv">
    <div id="VISDiv">
      <h1>VIS</h1>
      <p id="VIS"></p>
    </div>
    <div id="UVDiv">
      <h1>UV</h1>
      <p id="UV"></p>
    </div>
    <div id="IRDiv">
      <h1>IR</h1>
      <p id="IR"></p>
    </div>
  </div>
</template>

<script>
export default {
  name: "GY1145Sensor",
  props: {
    msg: String
  }
};
setInterval(async () => {
  let data = await fetch("http://localhost:2000/GY1145", {
  
}).then(function(response) {
  // Do something with response
   //console.log(response.text());
    return response.json();
});
//console.log(data)
document.getElementById("VIS").innerHTML = data.VIS;
document.getElementById("UV").innerHTML = data.UV;
document.getElementById("IR").innerHTML = data.IR;

}, 5000);
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
#outherDiv {
  background-color: aqua;
}
#IRDiv {
  background-color: blue;
}
#UVDiv {
  background-color: red;
}
#VISDiv {
  background-color: green;
}
</style>
