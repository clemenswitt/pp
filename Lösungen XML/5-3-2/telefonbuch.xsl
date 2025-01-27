<?xml version="1.0" encoding="iso8859-1" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:template match="/">
		<html><head></head><body>
			<H1>Adressbuch</H1>
			<table>
				<tr>
					<th>Vorname</th>
					<th>Name</th>
					<th>Straße</th>
					<th>Postleitzahl</th>
					<th>Ort</th>
				</tr>
				
				<xsl:for-each select="telefonbuch/verweis">
					<tr>
						<td align="center"><xsl:value-of select="vorname"/></td>
						<td align="center"><xsl:value-of select="name"/></td>
						<td align="center"><xsl:value-of select="strasse"/></td>
						<td align="center"><xsl:value-of select="postleitzahl"/></td>
						<td align="center"><xsl:value-of select="ort"/></td>
					</tr>
				</xsl:for-each>
			</table>
		</body></html>
	</xsl:template>
</xsl:stylesheet>