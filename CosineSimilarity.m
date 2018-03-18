function [Similaritys,test]= CosineSimilarity(LineVectors,SupportLineVector)
[m,n] = size(LineVectors);
LineVectors = double(LineVectors);

Similaritys = double(zeros(m,1));
%SupportLineVector = double([5 5]);
for i=1:m
    Similaritys(i) = (LineVectors(i,1)*SupportLineVector(1) + LineVectors(i,2)*SupportLineVector(2)) / (  sqrt(sum(LineVectors(i,:).^2)) * sqrt(sum(SupportLineVector(:).^2)) );
    disp((LineVectors(i,1)*SupportLineVector(1) + LineVectors(i,2)*SupportLineVector(2)));
    disp('/');
    disp(  sqrt(sum(LineVectors(i).^2)) );
    disp(  sqrt(sum(SupportLineVector.^2)) );
end

