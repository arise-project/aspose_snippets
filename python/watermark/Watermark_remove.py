from aspose.pdf import (
    WatermarkArtifact,
    Artifact,
    Document,
    SaveFormat
)


def remove():
    path_source = "../../TestData/test_with_watermark.pdf"
    doc = Document(path_source)

    if doc.Pages[1].Artifacts[1].Subtype == Artifact.ArtifactSubtype.Watermark:
        doc.Pages[1].Artifacts.Delete(doc.Pages[1].Artifacts[1])

    #save result pdf to file
    doc.Save("remove_watermark.pdf", SaveFormat.PDF)
        