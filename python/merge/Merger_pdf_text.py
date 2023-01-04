from aspose.pdf import (
    Document
)

from aspose.pdf import (
    Document
)

from aspose.pdf.text import (
    TextAbsorber
)


def pdf_to_text():
    path_source1 = "../../TestData/test.pdf"
    path_source2 = "../../TestData/Second/test.pdf"

    # read pdf file to Aspose Document
    first_doc = Document(path_source1)
    second_doc = Document(path_source2)

    # create empty pdf document
    output_doc = Document()

    # set less memory usage with unload instead of fast performance
    output_doc.enable_object_unload = True

    for page in first_doc.pages:
        # add page from one document to another directly
        output_doc.pages.add(page)

    for page in second_doc.pages:
        # add page from one document to another directly
        output_doc.pages.add(page)

    # create text absorber for extract text
    text_absorber = TextAbsorber()
    output_doc.pages.accept(text_absorber)
    extracted_text = text_absorber.text

    # save content to text file
    with open("Merger_pdf_text.txt", "w") as f:
        f.write(extracted_text)
