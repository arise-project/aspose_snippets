from aspose.pdf import (
    Rectangle,
    SaveFormat,
    Document
)

from PIL import Image
import tifffile
import io


def tiff_to_pdf():
    path_source1 = "../../TestData/MultipleFormats.tif"
    path_source2 = "../../TestData/Second/MultipleFormats.tif"

    multi_image1 = tifffile.TiffFile(path_source1)
    multi_image2 = tifffile.TiffFile(path_source2)

    # make list of tiff images to merge
    images = [multi_image1, multi_image2]

    # create empty pdf document
    output_doc = Document()

    for multiImage in images:
        # iterate through tiff frames
        for frame in multiImage.pages:
            # set active frame to work with
            fp = io.BytesIO(frame.asarray())
            # format = Image.registered_extensions()['.' + "jpg"]
            # multiImage.save(fp, format)

            # add new page to document
            page = output_doc.pages.add()

            page.page_info.margin.bottom = 0
            page.page_info.margin.top = 0
            page.page_info.margin.left = 0
            page.page_info.margin.right = 0
            page.page_info.width = frame.imagewidth
            page.page_info.height = frame.imagelength

            # read image dimensions to pdf page rectangle
            rect = Rectangle(0, 0, frame.imagewidth - 1, frame.imagelength - 1, True)

            # add document image to specific page
            page.add_image(fp, rect)

    # save result pdf to file
    output_doc.save("Merger_tiff_pdf.pdf", SaveFormat.Pdf)
