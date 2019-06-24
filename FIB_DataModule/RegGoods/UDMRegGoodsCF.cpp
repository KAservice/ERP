#include "vcl.h"
#pragma hdrstop  
#include "UDMRegGoodsCF.h"   
#include "UDMRegGoodsImpl.h"  
#include "IDMRegGoods.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMRegGoodsCF::TDMRegGoodsCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMRegGoodsCF::~TDMRegGoodsCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMRegGoodsCF::kanQueryInterface(REFIID id_interface, void**ppv)  
{    
int result=0;  
if (id_interface==IID_IkanUnknown) 
	{  
	*ppv=static_cast<IkanUnknown*> (this);  
	result=-1;  
	} 
else if (id_interface==IID_IkanClassFactory) 
	{  
	*ppv=static_cast<IkanClassFactory*> (this); 
	result=-1; 
	} 
else  
	{   
	*ppv=NULL;  
	result=0;  
	return result;  
	} 
kanAddRef();
return result;  
}   
//---------------------------------------------------------------
int TDMRegGoodsCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMRegGoodsCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMRegGoodsCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMRegGoodsImpl * ob=new TDMRegGoodsImpl();  
		if (ob->kanQueryInterface(id_interface, ppv)==-1)   
			{       
			result=-1;  
			}    
		else     
			{           
			delete ob;   
			result=0;   
			}      
return result;  
}       
//---------------------------------------------------------------
