from aspose.pdf import (
    WatermarkArtifact,
    Document
)


def remove():
    pathSource = "../../TestData/test_with_watermark.pdf"
    doc = Document(pathSource)

    if doc.Pages[1].Artifacts[1].Subtype == Aspose.Pdf.Artifact.ArtifactSubtype.Watermark:
        doc.Pages[1].Artifacts.Delete(doc.Pages[1].Artifacts[1])

    #save result pdf to file
    doc.Save("test.pdf", SaveFormat.PDF)
        