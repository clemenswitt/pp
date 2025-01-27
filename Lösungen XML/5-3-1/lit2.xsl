<?xml version="1.0"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">

    <xsl:template match="/">
        <html>
            <head>
                <title></title>
            </head>
            <body>
                <table style="border: 5px outset">
                    <tr>
                        <th>Vorname</th>
                        <th>Name</th>
                        <th>Titel</th>
                        <th>Datum</th>
                        <th>Verlag</th>
                        <th>ISBN</th>
                    </tr>
                    <xsl:apply-templates select="literaturverzeichnis"/>
                </table>
            </body>
        </html>
    </xsl:template>
    <xsl:template match="literaturverzeichnis">
        <xsl:for-each select="verweis">
            <tr>
                <td><xsl:value-of select="vorname"/></td>
                <td><xsl:value-of select="name"/></td>
                <td><xsl:value-of select="titel"/></td>
                <td><xsl:value-of select="datum"/></td>
                <td><xsl:value-of select="verlag"/></td>
                <td><xsl:value-of select="isbn"/></td>
            </tr>
        </xsl:for-each>
    </xsl:template>
</xsl:stylesheet>
