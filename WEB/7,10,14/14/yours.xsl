<?xml version="1.0"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>
<body>
<h2>Studentt Information</h2>
<table border="1">
<tr bgcolor = "blue">
<th>name</th>
<th>reg</th>
<th>dept</th>
<th>year</th>
<th>sub</th>
</tr>
<xsl:for-each select = "catalog/cd">
<xsl:sort select = " artist"/>
<tr>
<td><xsl:vslue-of select="name"/></td>
<td><xsl:vslue-of select="reg"/></td>
<td><xsl:vslue-of select="dept"/></td>
<td><xsl:vslue-of select="year"/></td>
<td><xsl:vslue-of select="sub"/></td>
</tr>
</xsl:for-each>
</table>
</body>
</html>
</xsl:template>
</xsl:stylesheet>