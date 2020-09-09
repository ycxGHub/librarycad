//
// Created by ycx on 2020/09/08.
//

#include "drw_imp.h"
bool drw_imp::fileExport(const std::string &file, DRW::Version v, bool binary, dx_data *fData) {
    cData = fData;
    dxfW = new dxfRW(file.c_str());
    bool success = dxfW->write(this, v, binary);
    delete dxfW;
    return success;
}

void drw_imp::writeEntity(DRW_Entity *e) {
    switch (e->eType) {
        case DRW::POINT:
            dxfW->writePoint(static_cast<DRW_Point*>(e));
            break;
        case DRW::LINE:
            dxfW->writeLine(static_cast<DRW_Line*>(e));
            break;
        case DRW::CIRCLE:
            dxfW->writeCircle(static_cast<DRW_Circle*>(e));
            break;
        case DRW::ARC:
            dxfW->writeArc(static_cast<DRW_Arc*>(e));
            break;
        case DRW::SOLID:
            dxfW->writeSolid(static_cast<DRW_Solid*>(e));
            break;
        case DRW::ELLIPSE:
            dxfW->writeEllipse(static_cast<DRW_Ellipse*>(e));
            break;
        case DRW::LWPOLYLINE:
            dxfW->writeLWPolyline(static_cast<DRW_LWPolyline*>(e));
            break;
        case DRW::POLYLINE:
            dxfW->writePolyline(static_cast<DRW_Polyline*>(e));
            break;
        case DRW::SPLINE:
            dxfW->writeSpline(static_cast<DRW_Spline*>(e));
            break;
//    case RS2::EntitySplinePoints:
//        writeSplinePoints(static_cast<DRW_Point*>(e));
//        break;
//    case RS2::EntityVertex:
//        break;
        case DRW::INSERT:
            dxfW->writeInsert(static_cast<DRW_Insert*>(e));
            break;
        case DRW::MTEXT:
            dxfW->writeMText(static_cast<DRW_MText*>(e));
            break;
        case DRW::TEXT:
            dxfW->writeText(static_cast<DRW_Text*>(e));
            break;
        case DRW::DIMLINEAR:
        case DRW::DIMALIGNED:
        case DRW::DIMANGULAR:
        case DRW::DIMANGULAR3P:
        case DRW::DIMRADIAL:
        case DRW::DIMDIAMETRIC:
        case DRW::DIMORDINATE:
            dxfW->writeDimension(static_cast<DRW_Dimension*>(e));
            break;
        case DRW::LEADER:
            dxfW->writeLeader(static_cast<DRW_Leader*>(e));
            break;
        case DRW::HATCH:
            dxfW->writeHatch(static_cast<DRW_Hatch*>(e));
            break;
        case DRW::IMAGE:
            dxfW->writeImage(static_cast<DRW_Image*>(e), static_cast<dx_ifaceImg*>(e)->path);
            break;
        default:
            break;
    }
}
