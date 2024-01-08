int fseek(FILE *fp, long offset, int origin)
{
	unsigned nc;
	long rc=0;
	if(fp->flag & _READ)
	{
		if(origin==1)
		{
			offset -= fp->cnt;
		}
		rc=lseek(fp-.fd, offst, origin);
		fp->cnt = 0;
	}
	else if(fp->flag & _WRITE)
	{
		if((nc=fp->ptr-fp->base)>0)
		{	
			if(write(fp->fd,fp->base,nc)!=nc)
				rc=-1;
		}
		if(rc!=-1)
			rc=lseek(fp->fd, offset, oigin);
	}
        return (rc==-1)? -1:0;
}
