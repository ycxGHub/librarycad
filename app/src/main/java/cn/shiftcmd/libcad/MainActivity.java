package cn.shiftcmd.libcad;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.Manifest;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;

import java.io.File;

public class MainActivity extends AppCompatActivity {
    Coordinate p1=new Coordinate(0,0,0);
    Coordinate p2=new Coordinate(0,100,0);
    Coordinate p3=new Coordinate(100,100,0);
    Coordinate p4=new Coordinate(100,0,0);
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            requestPermissions(new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE,Manifest.permission.READ_EXTERNAL_STORAGE},1000);
        }
        File file=Environment.getExternalStorageDirectory();
        File dxfFile=new File(file,"dxfFile.dxf");
        DxfWriter dxfWriter =new DxfWriter(dxfFile.getAbsolutePath());
        dxfWriter.writeCoord(p1);
        dxfWriter.writeCoord(p2);
        dxfWriter.writeCoord(p3);
        dxfWriter.writeCoord(p4);
        dxfWriter.writeLine(p1,p2,10.0);
        dxfWriter.writeLine(p2,p3,20.0);
        dxfWriter.writeLine(p3,p4,30.0);
        dxfWriter.writeText(p1,p2,"测试个中文");
        dxfWriter.writeText(p2,p3,"Test English");
        dxfWriter.writeLine(p4,p1,40.0);
        dxfWriter.writeCircle(p1.middleOf(p3),40);
        dxfWriter.writeToFile();
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
    }
}