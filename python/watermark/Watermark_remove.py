from aspose.pdf import (
    WatermarkArtifact,
    Artifact,
    ArtifactSubtype,
    Document,
    SaveFormat
)


def remove():
    path_source = "../../TestData/test_with_watermark.pdf"
    doc = Document(path_source)

    if doc.Pages[1].Artifacts[1].Subtype == ArtifactSubtype.Watermark:
        doc.Pages[1].Artifacts.Delete(doc.Pages[1].Artifacts[1])

    #save result pdf to file
    doc.Save("test.pdf", SaveFormat.PDF)
        