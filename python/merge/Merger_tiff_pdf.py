from aspose.pdf import (
    SaveFormat,
    PdfImage,
    PdfImage,
    Document
)

from PIL import Image
import tifffile
import io

def tiff_to_pdf():
    path_source1 = "../../TestData/test.tiff"
    path_source2 = "../../TestData/Second/test.tiff"

    multi_image1 = tifffile.imread(path_source1)
    multi_image2 = tifffile.imread(path_source2)

    # make list of tiff images to merge
    images = [multi_image1, multi_image2]

    # create empty pdf document
    output_doc = Document

    for multiImage in images:
        # iterate through tiff frames
        for frame in range(0, multiImage.n_frames):
            # set active frame to work with
            multiImage.seek(frame)
            fp = io.BytesIO()
            format = Image.registered_extensions()['.' + "jpg"]
            multiImage.save(fp, format)


            # add new page to document
            page = output_doc.pages.add()

            page.page_info.Margin.Bottom = 0
            page.page_info.Margin.Top = 0
            page.page_info.Margin.Left = 0
            page.page_info.Margin.Right = 0
            page.page_info.width = multiImage.width
            page.page_info.height = multiImage.height

            # create new image into document
            image = PdfImage
            # set image source to memory stream
            image.image_stream = fp

            # add document image to specific page
            page.Paragraphs.add(image)

    # save result pdf to file
    output_doc.save("Merger_tiff_pdf.pdf", SaveFormat.Pdf)
