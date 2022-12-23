from Aspose.Pdf import (
    SaveFormat,
    TeXLoadOptions,
    Document
)

def tex_to_pdf(self):
    pathSource1 = "../../TestData/test.tex"
    pathSource2 = "../../TestData/Second/test.tex"

    opt1 = TeXLoadOptions()
    # Cancels ligatures in all fonts
    opt1.NoLigatures = False
    # Rasterize scientific formulas to images
    opt1.RasterizeFormulas = True
    # Print parsing steps details to console output
    opt1.ShowTerminalOutput = True

    # TeX files can be parsed and loaded as Aspose Document
    firstDoc = Document(pathSource1, opt1)

    opt1 = TeXLoadOptions()
    # Set ligatures in all fonts
    opt1.NoLigatures = False
    # Rasterize scientific formulas to images
    opt1.RasterizeFormulas = True
    # Print parsing steps details to console output
    opt1.ShowTerminalOutput = True

    secondDoc = Document(pathSource2, opt1)

    outputDoc = Document()

    # set less memory usage with unload instead of fast performance
    outputDoc.EnableObjectUnload = True

    for page in firstDoc.Pages:
        # add page from one document to another directly
        outputDoc.Pages.Add(page)

    for page in secondDoc.Pages:
        # add page from one document to another directly
        outputDoc.Pages.Add(page)

    # save result pdf to file
    outputDoc.Save("test.pdf", SaveFormat.Pdf)
