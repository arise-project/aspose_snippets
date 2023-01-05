from aspose.pdf import (
    SaveFormat,
    TxtLoadOptions,
    Document
)

from aspose.pdf.facades import (
    PdfFileEditor
)

from aspose.pdf.text import (
    TextAbsorber
)

from pathlib import Path


def TXT():
    path_source = "../../TestData/test.txt"
    pdf_editor = PdfFileEditor()

    doc = Document(path_source, TxtLoadOptions())
    # save input text to pdf to file
    doc.save("test.pdf", SaveFormat.PDF)

    pdf_editor.split_to_pages("test.pdf", "p_%NUM%.pdf")
    index = 1
    files = Path("./").glob('p_*.pdf')

    for path in files:
        page = Document(path.name)
        text_absorber = TextAbsorber()
        page.pages.accept(text_absorber)
        extracted_text = text_absorber.text
        file = open("text_" + str(index) + ".txt", "w+")
        file.write(extracted_text)
        index = index + 1
