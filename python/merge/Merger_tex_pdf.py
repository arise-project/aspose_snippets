from aspose.pdf import (
    SaveFormat,
    TeXLoadOptions,
    Document
)


def tex_to_pdf():
    path_source1 = "../../TestData/test.tex"
    path_source2 = "../../TestData/Second/test.tex"

    opt1 = TeXLoadOptions()
    # Cancels ligatures in all fonts
    opt1.no_ligatures = False
    # Rasterize scientific formulas to images
    opt1.rasterize_formulas = True
    # Print parsing steps details to console output
    opt1.show_terminal_output = True

    # TeX files can be parsed and loaded as Aspose Document
    first_doc = Document(path_source1, opt1)

    opt1 = TeXLoadOptions()
    # Set ligatures in all fonts
    opt1.no_ligatures = False
    # Rasterize scientific formulas to images
    opt1.rasterize_formulas = True
    # Print parsing steps details to console output
    opt1.show_terminal_output = True

    second_doc = Document(path_source2, opt1)

    output_doc = Document()

    # set less memory usage with unload instead of fast performance
    output_doc.enable_object_unload = True

    for page in first_doc.pages:
        # add page from one document to another directly
        output_doc.pages.add(page)

    for page in second_doc.pages:
        # add page from one document to another directly
        output_doc.pages.add(page)

    # save result pdf to file
    output_doc.save("test.pdf", SaveFormat.Pdf)
