<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
            <head>
                <title>Ristorante TARTUFFO Menu Transformed Document</title>
            </head>
            <body>
                <h1>Ristorante TARTUFO</h1>
                <xsl:apply-templates select="root"/>
            </body>
        </html>
    </xsl:template>

    <xsl:template match="root">
        <ul>
            <xsl:apply-templates/>
        </ul>
    </xsl:template>

    <xsl:template match="Pizza | Pasta | Vino">
        <li>
            <xsl:value-of select="name()"/>:
            <ul>
                <xsl:apply-templates/>
            </ul>
        </li>
    </xsl:template>

    <xsl:template match="Name | ID | Size | Typ | Menge | Zutaten">
        <li>
            <xsl:value-of select="name()"/>: <xsl:value-of select="."/>
        </li>
    </xsl:template>
</xsl:stylesheet>