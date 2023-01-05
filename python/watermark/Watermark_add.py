from pprint import pprint

from aspose.pdf import (
    WatermarkArtifact,
    HorizontalAlignment,
    VerticalAlignment,
    Document,
    SaveFormat
)


def add():
    path_source = "../../TestData/test.pdf"
    watermark_source = "../../TestData/test.jpg"
    doc = Document(path_source)

    artifact = WatermarkArtifact()
    artifact.set_image(watermark_source)

    artifact.artifact_horizontal_alignment = HorizontalAlignment.CENTER
    artifact.artifact_vertical_alignment = VerticalAlignment.CENTER
    artifact.rotation = 15
    artifact.opacity = 1
    artifact.is_background = True

    doc.pages[1].artifacts.append(artifact)

    # save result pdf to file
    doc.save("add_watermark.pdf", SaveFormat.PDF)
    