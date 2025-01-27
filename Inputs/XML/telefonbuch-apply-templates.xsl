<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">

    <!-- Haupttemplate für die gesamte Lösungen XML-Datei -->
    <xsl:template match="/">
        <html>
            <body>
                <h1>Telefonbuch</h1>
                <table border="1">
                    <tr>
                        <th>Name</th>
                        <th>Telefon</th>
                    </tr>
                    <!-- Anwenden von Templates auf alle 'eintrag'-Elemente -->
                    <xsl:apply-templates select="telefonbuch/eintrag"/>
                </table>
            </body>
        </html>
    </xsl:template>

    <!-- Template für ein einzelnes 'eintrag'-Element -->
    <xsl:template match="eintrag">
        <tr>
            <td><xsl:value-of select="name"/></td>
            <td><xsl:value-of select="telefon"/></td>
        </tr>
    </xsl:template>

</xsl:stylesheet>