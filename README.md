# Namensliste-Verwaltungsprogramm

## Funktionalitäten

### Dynamische Speicherverwaltung
Das Programm nutzt dynamische Speicherverwaltung, um eine Liste von Nachnamen effizient zu verarbeiten. Diese Namen basieren auf Volkszählungsdaten aus dem Jahr 2010 in den USA.

### Verarbeitung und Analyse von Namen
- **Häufige Namen**: Das Programm kann die häufigsten Namen aus der Liste extrahieren und anzeigen. Standardmäßig ist es konfiguriert, die 20 häufigsten Namen anzuzeigen.
- **Name und Häufigkeit**: Für jeden gelisteten Namen zeigt das Programm sowohl den Namen als auch seine Häufigkeit an.

### Interaktive Benutzereingabe
- **Suchfunktion**: Nutzer können einen Namen eingeben, und das Programm zeigt, wie oft dieser Name in der Liste vorkommt.
- **Top-N-Filter**: Nutzer können eine Zahl n eingeben, um die n-häufigsten Namen in der Liste zu sehen.

### Effiziente Datenstrukturen
- **Dynamische Listenanpassung**: Die Liste passt ihre Größe dynamisch an, basierend darauf, wie viele Einträge aktuell benötigt werden, was eine effiziente Speichernutzung ermöglicht.
- **Strukturierte Datenverwaltung**: Jeder Eintrag in der Liste ist in einer Struktur vom Typ `entry_t` organisiert, die eine optimierte Verarbeitung und Zugriff ermöglicht.

### Ausgabefunktionen
- **Listenausgabe**: Das Programm kann die sortierte Liste der häufigsten Namen ausgeben.
- **Frequenzbasierte Visualisierung**: Es kann auch die Häufigkeit jedes Namens visuell in einer formatierten Ausgabe darstellen.

### Speicherverwaltung
- **Speicheroptimierung**: Nach der Verwendung gibt das Programm den reservierten Speicher wieder frei, was die Systemeffizienz erhöht.

## Leistung
Das Programm ist für schnelle Such- und Analyseoperationen optimiert und kann große Datensätze effizient verarbeiten. Es ist besonders nützlich für demografische Studien und Datenanalyse in großen Datensammlungen.
