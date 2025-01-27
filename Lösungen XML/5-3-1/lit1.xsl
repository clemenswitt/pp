<?xml version="1.0"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">

    <xsl:template match="/">
        <html>
            <head>
                <title></title>
            </head>
            <body>
                <xsl:apply-templates select="literaturverzeichnis"/>
            </body>

        </html>
    </xsl:template>
    <xsl:template match="literaturverzeichnis">
        <xsl:for-each select="verweis">
            <p>
                <strong>Autor </strong>
                    <xsl:value-of select="vorname"/><xsl:value-of select="name"/>
                <strong>Titel: </strong>
                    <xsl:value-of select="titel"/>
                <br/>
                <xsl:value-of select="datum"/> ,
                <xsl:value-of select="verlag"/> ,
                <xsl:value-of select="isbn"/> ,
                <xsl:value-of select="preis"/>
            </p>
        </xsl:for-each>
    </xsl:template>
</xsl:stylesheet>
