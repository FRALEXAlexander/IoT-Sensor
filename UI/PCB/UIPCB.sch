<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.5.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="3" name="Route3" color="4" fill="3" visible="no" active="no"/>
<layer number="4" name="Route4" color="1" fill="4" visible="no" active="no"/>
<layer number="5" name="Route5" color="4" fill="4" visible="no" active="no"/>
<layer number="6" name="Route6" color="1" fill="8" visible="no" active="no"/>
<layer number="7" name="Route7" color="4" fill="8" visible="no" active="no"/>
<layer number="8" name="Route8" color="1" fill="2" visible="no" active="no"/>
<layer number="9" name="Route9" color="4" fill="2" visible="no" active="no"/>
<layer number="10" name="Route10" color="1" fill="7" visible="no" active="no"/>
<layer number="11" name="Route11" color="4" fill="7" visible="no" active="no"/>
<layer number="12" name="Route12" color="1" fill="5" visible="no" active="no"/>
<layer number="13" name="Route13" color="4" fill="5" visible="no" active="no"/>
<layer number="14" name="Route14" color="1" fill="6" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="24" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="ESP32-DEVKITV1">
<packages>
<package name="ESP32-DEVKITV1">
<pad name="3V3" x="-16.52" y="-12.27" drill="1" diameter="1.9304"/>
<pad name="GND@2" x="-13.98" y="-12.27" drill="1" diameter="1.9304"/>
<pad name="D15" x="-11.44" y="-12.27" drill="1" diameter="1.9304"/>
<pad name="D2" x="-8.9" y="-12.27" drill="1" diameter="1.9304"/>
<pad name="D4" x="-6.36" y="-12.27" drill="1" diameter="1.9304"/>
<pad name="D16" x="-3.82" y="-12.27" drill="1" diameter="1.9304"/>
<pad name="D17" x="-1.28" y="-12.27" drill="1" diameter="1.9304"/>
<pad name="D5" x="1.26" y="-12.27" drill="1" diameter="1.9304"/>
<pad name="D18" x="3.8" y="-12.27" drill="1" diameter="1.9304"/>
<pad name="D19" x="6.34" y="-12.27" drill="1" diameter="1.9304"/>
<pad name="D21" x="8.88" y="-12.27" drill="1" diameter="1.9304"/>
<pad name="D3" x="11.42" y="-12.27" drill="1" diameter="1.9304"/>
<pad name="D1" x="13.96" y="-12.27" drill="1" diameter="1.9304"/>
<pad name="D22" x="16.5" y="-12.27" drill="1" diameter="1.9304"/>
<pad name="D23" x="19.04" y="-12.27" drill="1" diameter="1.9304"/>
<pad name="VIN" x="-16.52" y="13.135" drill="1" diameter="1.9304"/>
<pad name="GND@1" x="-13.98" y="13.135" drill="1" diameter="1.9304"/>
<pad name="D13" x="-11.44" y="13.135" drill="1" diameter="1.9304"/>
<pad name="D12" x="-8.9" y="13.135" drill="1" diameter="1.9304"/>
<pad name="D14" x="-6.36" y="13.135" drill="1" diameter="1.9304"/>
<pad name="D27" x="-3.82" y="13.135" drill="1" diameter="1.9304"/>
<pad name="D26" x="-1.28" y="13.135" drill="1" diameter="1.9304"/>
<pad name="D25" x="1.26" y="13.135" drill="1" diameter="1.9304"/>
<pad name="D33" x="3.8" y="13.135" drill="1" diameter="1.9304"/>
<pad name="D32" x="6.34" y="13.135" drill="1" diameter="1.9304"/>
<pad name="D35" x="8.88" y="13.135" drill="1" diameter="1.9304"/>
<pad name="D34" x="11.42" y="13.135" drill="1" diameter="1.9304"/>
<pad name="D39" x="13.96" y="13.135" drill="1" diameter="1.9304"/>
<pad name="D36" x="16.5" y="13.135" drill="1" diameter="1.9304"/>
<pad name="EN" x="19.04" y="13.135" drill="1" diameter="1.9304"/>
<text x="-15.86" y="-9.93" size="1.016" layer="21" font="vector" rot="R90">3V3</text>
<text x="-13.32" y="-9.93" size="1.016" layer="21" font="vector" rot="R90">GND</text>
<text x="-10.78" y="-9.93" size="1.016" layer="21" font="vector" rot="R90">IO15</text>
<text x="-8.24" y="-9.93" size="1.016" layer="21" font="vector" rot="R90">IO2</text>
<text x="-5.7" y="-9.93" size="1.016" layer="21" font="vector" rot="R90">IO4</text>
<text x="-3.16" y="-9.93" size="1.016" layer="21" font="vector" rot="R90">IO16</text>
<text x="-0.62" y="-9.93" size="1.016" layer="21" font="vector" rot="R90">IO17</text>
<text x="1.92" y="-9.93" size="1.016" layer="21" font="vector" rot="R90">IO5</text>
<text x="4.46" y="-9.93" size="1.016" layer="21" font="vector" rot="R90">IO18</text>
<text x="7" y="-9.93" size="1.016" layer="21" font="vector" rot="R90">IO19</text>
<text x="9.54" y="-9.93" size="1.016" layer="21" font="vector" rot="R90">IO21</text>
<text x="12.08" y="-9.93" size="1.016" layer="21" font="vector" rot="R90">IO3</text>
<text x="14.62" y="-9.93" size="1.016" layer="21" font="vector" rot="R90">IO1</text>
<text x="17.16" y="-9.93" size="1.016" layer="21" font="vector" rot="R90">IO22</text>
<text x="19.7" y="-9.93" size="1.016" layer="21" font="vector" rot="R90">IO23</text>
<text x="-15.84" y="7.79" size="1.016" layer="21" font="vector" rot="R90">VIN</text>
<text x="-13.3" y="7.79" size="1.016" layer="21" font="vector" rot="R90">GND</text>
<text x="-10.76" y="7.79" size="1.016" layer="21" font="vector" rot="R90">IO13</text>
<text x="-8.22" y="7.79" size="1.016" layer="21" font="vector" rot="R90">IO12</text>
<text x="-5.68" y="7.79" size="1.016" layer="21" font="vector" rot="R90">IO14</text>
<text x="-3.14" y="7.79" size="1.016" layer="21" font="vector" rot="R90">IO27</text>
<text x="-0.6" y="7.79" size="1.016" layer="21" font="vector" rot="R90">IO26</text>
<text x="1.94" y="7.79" size="1.016" layer="21" font="vector" rot="R90">IO25</text>
<text x="4.48" y="7.79" size="1.016" layer="21" font="vector" rot="R90">IO33</text>
<text x="7.02" y="7.79" size="1.016" layer="21" font="vector" rot="R90">IO32</text>
<text x="9.56" y="7.79" size="1.016" layer="21" font="vector" rot="R90">IO35</text>
<text x="12.1" y="7.79" size="1.016" layer="21" font="vector" rot="R90">IO34</text>
<text x="14.64" y="5.25" size="1.016" layer="21" font="vector" rot="R90">VN/IO39</text>
<text x="17.18" y="5.25" size="1.016" layer="21" font="vector" rot="R90">VP/IO36</text>
<text x="19.72" y="7.79" size="1.016" layer="21" font="vector" rot="R90">EN</text>
<text x="1.42" y="-1.91" size="1.9304" layer="21" font="vector">ESP32-Devkit V1</text>
<wire x1="-26.65" y1="14.605" x2="25.35" y2="14.605" width="0.254" layer="21"/>
<wire x1="25.35" y1="14.605" x2="25.35" y2="-13.93" width="0.254" layer="21"/>
<wire x1="25.35" y1="-13.93" x2="-26.65" y2="-13.93" width="0.254" layer="21"/>
<wire x1="-26.65" y1="-13.93" x2="-26.65" y2="14.605" width="0.254" layer="21"/>
<text x="-17.78" y="15.24" size="1.27" layer="21">&gt;NAME</text>
<text x="11.35" y="-15.97" size="1.27" layer="27">ESP32-DEVKITV1</text>
</package>
</packages>
<symbols>
<symbol name="ESP32-DEVKITV1">
<wire x1="-25.4" y1="-12.7" x2="-25.4" y2="12.7" width="0.254" layer="94"/>
<wire x1="-25.4" y1="12.7" x2="16" y2="12.7" width="0.254" layer="94"/>
<wire x1="16" y1="12.7" x2="16" y2="-12.7" width="0.254" layer="94"/>
<wire x1="16" y1="-12.7" x2="-25.4" y2="-12.7" width="0.254" layer="94"/>
<pin name="3V3" x="-22.86" y="-17.78" length="middle" rot="R90"/>
<pin name="GND@2" x="-20.32" y="-17.78" length="middle" rot="R90"/>
<pin name="IO15" x="-17.78" y="-17.78" length="middle" rot="R90"/>
<pin name="IO2" x="-15.24" y="-17.78" length="middle" rot="R90"/>
<pin name="IO4" x="-12.7" y="-17.78" length="middle" rot="R90"/>
<pin name="IO16" x="-10.16" y="-17.78" length="middle" rot="R90"/>
<pin name="IO17" x="-7.62" y="-17.78" length="middle" rot="R90"/>
<pin name="IO5" x="-5.08" y="-17.78" length="middle" rot="R90"/>
<pin name="IO18" x="-2.54" y="-17.78" length="middle" rot="R90"/>
<pin name="IO19" x="0" y="-17.78" length="middle" rot="R90"/>
<pin name="IO21" x="2.54" y="-17.78" length="middle" rot="R90"/>
<pin name="IO3" x="5.08" y="-17.78" length="middle" rot="R90"/>
<pin name="IO1" x="7.62" y="-17.78" length="middle" rot="R90"/>
<pin name="IO22" x="10.16" y="-17.78" length="middle" rot="R90"/>
<pin name="IO23" x="12.7" y="-17.78" length="middle" rot="R90"/>
<pin name="EN" x="12.7" y="17.78" length="middle" rot="R270"/>
<pin name="VP-OI36" x="10.16" y="17.78" length="middle" rot="R270"/>
<pin name="VN-IO39" x="7.62" y="17.78" length="middle" rot="R270"/>
<pin name="IO34" x="5.08" y="17.78" length="middle" rot="R270"/>
<pin name="IO35" x="2.54" y="17.78" length="middle" rot="R270"/>
<pin name="IO32" x="0" y="17.78" length="middle" rot="R270"/>
<pin name="IO33" x="-2.54" y="17.78" length="middle" rot="R270"/>
<pin name="IO25" x="-5.08" y="17.78" length="middle" rot="R270"/>
<pin name="IO26" x="-7.62" y="17.78" length="middle" rot="R270"/>
<pin name="IO27" x="-10.16" y="17.78" length="middle" rot="R270"/>
<pin name="IO14" x="-12.7" y="17.78" length="middle" rot="R270"/>
<pin name="IO12" x="-15.24" y="17.78" length="middle" rot="R270"/>
<pin name="IO13" x="-17.78" y="17.78" length="middle" rot="R270"/>
<pin name="GND@1" x="-20.32" y="17.78" length="middle" rot="R270"/>
<pin name="VIN" x="-22.86" y="17.78" length="middle" rot="R270"/>
<text x="-26.67" y="5.08" size="1.27" layer="95" rot="R90">&gt;NAME</text>
<text x="18.4" y="-12.7" size="1.27" layer="96" rot="R90">ESP32-DEVKITV1</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="ESP32DEVKITV1">
<gates>
<gate name="G$1" symbol="ESP32-DEVKITV1" x="0" y="0"/>
</gates>
<devices>
<device name="" package="ESP32-DEVKITV1">
<connects>
<connect gate="G$1" pin="3V3" pad="3V3"/>
<connect gate="G$1" pin="EN" pad="EN"/>
<connect gate="G$1" pin="GND@1" pad="GND@1"/>
<connect gate="G$1" pin="GND@2" pad="GND@2"/>
<connect gate="G$1" pin="IO1" pad="D1"/>
<connect gate="G$1" pin="IO12" pad="D12"/>
<connect gate="G$1" pin="IO13" pad="D13"/>
<connect gate="G$1" pin="IO14" pad="D14"/>
<connect gate="G$1" pin="IO15" pad="D15"/>
<connect gate="G$1" pin="IO16" pad="D16"/>
<connect gate="G$1" pin="IO17" pad="D17"/>
<connect gate="G$1" pin="IO18" pad="D18"/>
<connect gate="G$1" pin="IO19" pad="D19"/>
<connect gate="G$1" pin="IO2" pad="D2"/>
<connect gate="G$1" pin="IO21" pad="D21"/>
<connect gate="G$1" pin="IO22" pad="D22"/>
<connect gate="G$1" pin="IO23" pad="D23"/>
<connect gate="G$1" pin="IO25" pad="D25"/>
<connect gate="G$1" pin="IO26" pad="D26"/>
<connect gate="G$1" pin="IO27" pad="D27"/>
<connect gate="G$1" pin="IO3" pad="D3"/>
<connect gate="G$1" pin="IO32" pad="D32"/>
<connect gate="G$1" pin="IO33" pad="D33"/>
<connect gate="G$1" pin="IO34" pad="D34"/>
<connect gate="G$1" pin="IO35" pad="D35"/>
<connect gate="G$1" pin="IO4" pad="D4"/>
<connect gate="G$1" pin="IO5" pad="D5"/>
<connect gate="G$1" pin="VIN" pad="VIN"/>
<connect gate="G$1" pin="VN-IO39" pad="D39"/>
<connect gate="G$1" pin="VP-OI36" pad="D36"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U$1" library="ESP32-DEVKITV1" deviceset="ESP32DEVKITV1" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="63.5" y="50.8" smashed="yes" rot="R90">
<attribute name="NAME" x="58.42" y="24.13" size="1.27" layer="95" rot="R180"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="5V" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="VIN"/>
<wire x1="35.56" y1="30.48" x2="35.56" y2="27.94" width="0.1524" layer="91"/>
<wire x1="35.56" y1="27.94" x2="45.72" y2="27.94" width="0.1524" layer="91"/>
<label x="43.18" y="22.86" size="1.778" layer="95"/>
</segment>
</net>
<net name="SDA" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="IO21"/>
<wire x1="96.52" y1="53.34" x2="81.28" y2="53.34" width="0.1524" layer="91"/>
<label x="88.9" y="50.8" size="1.778" layer="95"/>
</segment>
</net>
<net name="SCL" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="IO22"/>
<wire x1="81.28" y1="60.96" x2="99.06" y2="60.96" width="0.1524" layer="91"/>
<label x="86.36" y="63.5" size="1.778" layer="95"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
