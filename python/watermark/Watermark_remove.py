from aspose.pdf import (
    WatermarkArtifact,
    Artifact,
    Document,
    SaveFormat
)


def remove():
    path_source = "../../TestData/test_with_watermark.pdf"
    doc = Document(path_source)

    if doc.pages[1].artifacts[1].subtype == Artifact.ArtifactSubtype.WATERMARK:
        doc.pages[1].artifacts.delete(doc.pages[1].artifacts[1])

    # save result pdf to file
    doc.save("remove_watermark.pdf", SaveFormat.PDF)
        