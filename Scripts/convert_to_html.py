import os
import subprocess

root_dir = os.getcwd()
html_dir = os.path.join(root_dir, "HTML")

def convert_to_html(ipynb_file, output_dir):
    try:
        # Führe den nbconvert-Befehl aus
        subprocess.run(
            ["jupyter-nbconvert", "--to", "html", "--output-dir", output_dir, ipynb_file],
            check=True
        )
        print(f"Konvertierung abgeschlossen: {ipynb_file}")
    except subprocess.CalledProcessError as e:
        print(f"Fehler bei der Konvertierung von {ipynb_file}: {e}")

for root, dirs, files in os.walk(root_dir):
    for file in files:
        if file.endswith(".ipynb"):
            ipynb_path = os.path.join(root, file)
            convert_to_html(ipynb_path, html_dir)