from aspose.pdf import (
    WatermarkArtifact,
    Artifact,
    Document
)

import io


def get():
    path_source = "../../TestData/test_with_watermark.pdf"
    doc = Document(path_source)

    if doc.pages[1].artifacts[1].subtype == Artifact.ArtifactSubtype.WATERMARK:
        image_stream = io.FileIO(
            "get_watermark.jpg", 'x'
        )
        doc.pages[1].artifacts[1].image.save(image_stream)
        # fs.flush()
        # fs.close()
