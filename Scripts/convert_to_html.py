import os
import subprocess

def convert_to_html(ipynb_file, output_dir):
    try:
        subprocess.run(
            ["jupyter-nbconvert", "--to", "html", "--output-dir", output_dir, ipynb_file],
            check=True
        )
        print(f"Konvertierung abgeschlossen: {ipynb_file}")
    except subprocess.CalledProcessError as e:
        print(f"Fehler bei der Konvertierung von {ipynb_file}: {e}")

root_dir = os.getcwd()
notebook_dir = os.path.join(root_dir, 'Lösungen Python')
html_dir = os.path.join(root_dir, "HTML")

for root, dirs, files in os.walk(notebook_dir):
    for file in files:
        if file.endswith(".ipynb"):
            ipynb_path = os.path.join(root, file)
            convert_to_html(ipynb_path, html_dir)